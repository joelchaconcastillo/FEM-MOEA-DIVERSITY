#!/usr/bin/perl
use strict;
use warnings;
use Getopt::Long;
use threads;
use threads::shared;
use Thread::Queue;
use Time::HiRes qw(usleep nanosleep);
my $MachineFile;
my $ExecFile;
my $FileMF;
my $FileE;
my $FileOut;
my $ThreadQueue = Thread::Queue->new();
my %ListMachines:shared;
my $TotalProcessAvailables:shared;
my $Threads_limit = 0;
GetOptions (
		"M=s" => \$MachineFile,
		"E=s" => \$ExecFile,
		"T=i"=> \$Threads_limit
	 )
	or die ("Error in comand line arguments") ;
##Abrir archivos . . .
open($FileMF, '<', $MachineFile);
open($FileE, '<', $ExecFile);
open($FileOut, '>', "Result.txt" );
#Generate subrutines.....

sub BuildQueue{
		#Cargar todos los jobs a la cola compartida . . . .
	while( my $Exec = <$FileE>)
	{
		chomp $Exec;
		##Agregar los n procesos indicados por el header opcional
		if($Exec =~ m/<(\d+)>/) {
			$Exec = <$FileE>;
			chomp $Exec;
			for(my $i = 0; $i < $1; $i++)
			{
				my @List = split /~/, $Exec;
				$ThreadQueue->enqueue("Data: ".$List[0]." ~".$List[1]);
			}
		}
		else
		{
				  my @List = split /~/, $Exec;
				$ThreadQueue->enqueue("Data: ".$List[0]." ~".$List[1]);
		}
	}
	$ThreadQueue->end();
}
sub LoadMachines
{
	while(my $Machine = <$FileMF>)
	{
		chomp $Machine;
		my @List = split / /, $Machine;
		$ListMachines{$List[0]} = $List[1];
		$TotalProcessAvailables += $List[1];
	}

}
sub getMachineAvailable
{
		lock(%ListMachines);
		foreach my $key( keys %ListMachines)
		{
			if($ListMachines{$key} > 0)
			{
				$ListMachines{$key}--;
					return $key;
			}
				#print $key." ".$ListMachines{$key}."\n";
		}
		return "";
}
my $conta:shared;
sub ProcessQueue{
         while (defined(my $item = $ThreadQueue->dequeue())) {
					 	my @List = split /~/, $item;
							#if($ThreadQueue->pending())
							#{
							#	sleep($ThreadQueue->pending());
							#}
						my $FreeMachine = getMachineAvailable();
							while( !(defined $FreeMachine) ||  length($FreeMachine) < 2 )
							{
							#	sleep($ThreadQueue->pending());
								$FreeMachine = getMachineAvailable();
							}
							###En caso de que el host de destino rechaze la conexion debido  a que las conexiones 
							## se realizaron al mismo tiempo se reintenta constantemente...
print "Procesos finalizados.... ".$conta."\n";
                                                        $conta++;
							my $state = `ssh $FreeMachine $List[1] 2>&1 `;
                                                        if(defined($state) )
                                                        {
                                                          while( $state  =~ "ssh_exchange_identification")
                                                          {
                                                                $state = `ssh $FreeMachine $List[1] 2>&1 `;
                                                                sleep(10);
                                                          }
                                                        }
                                                        print $FileOut $List[0]."::\t $state \n";
                                                        #print "ssh $FreeMachine $List[1] \n";
                                                        

							lock(%ListMachines);
							$ListMachines{$FreeMachine}++;
		}
}
$TotalProcessAvailables = 0;
#Construir la cola
BuildQueue();
LoadMachines();
##Verificar el tamaño máximo de threads que se van a utilizar
if($TotalProcessAvailables <= $ThreadQueue->pending())
{
	$Threads_limit = $TotalProcessAvailables;
}else
{
	$Threads_limit = $ThreadQueue->pending();
}
print "Total de procesos disponibles $Threads_limit \n";
#Crear la lista de hilos que es el número de ejecuciones
# a distribuir en el cluster
my @thr = map {
	threads->create('ProcessQueue')
} 1 .. $Threads_limit;

#Ejecutar  y esperar a todos los threads en ejecución . . .
$_->join() for @thr;

#Cerrar ficheros
close($FileMF);
close($FileE);
close($FileOut);
