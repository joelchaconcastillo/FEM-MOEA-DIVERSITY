#Con este script se genera la lista de ejecuciones....
#!/usr/bin/perl
use strict;
use warnings;
use Getopt::Long;

my $file = "ExecutionFileDiversity";
my $fout;
open($fout, '>' ,$file);
my $PathAlgorithm =  `cd ..; pwd`;#"/home/joel.chacon/Current/MyResearchTopics/MOEA-D-Diversity/MOEAD-DE/vsd-moead-opt";
chomp $PathAlgorithm;

####Realizar la búsqueda del parámetro D inicial que proporcione mejores resultados
my @Conf =(
"UF1 30 2",
"UF2 30 2",
"UF3 30 2",
"UF4 30 2",
"UF5 30 2",
"UF6 30 2",
"UF7 30 2",
"UF8 30 3",
"UF9 30 3",
"UF10 30 3",
##"R2_DTLZ2_M5 30 5",
##"R2_DTLZ3_M5 30 5",
##"WFG1_M5     30 5",
"WFG1 24 2",
"WFG2 24 2",
"WFG3 24 2",
"WFG4 24 2",
"WFG5 24 2",
"WFG6 24 2",
"WFG7 24 2",
"WFG8 24 2",
"WFG9 24 2",
"DTLZ1 6 2",
"DTLZ2 11 2",
"DTLZ3 11 2",
"DTLZ4 11 2",
"DTLZ5 11 2",
"DTLZ6 11 2",
"DTLZ7 21 2",
"WFG1 24 3",
"WFG2 24 3",
"WFG3 24 3",
"WFG4 24 3",
"WFG5 24 3",
"WFG6 24 3",
"WFG7 24 3",
"WFG8 24 3",
"WFG9 24 3",
"DTLZ1 7 3",
"DTLZ2 12 3",
"DTLZ3 12 3",
"DTLZ4 12 3",
"DTLZ5 12 3",
"DTLZ6 12 3",
"DTLZ7 22 3");

my @DD =("0.0", "0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9", "1.0");
foreach my $Di (@DD)
{
	foreach my $line (@Conf)
	{
		for(my $Seed = 1; $Seed <=35; $Seed++) ##Realizar 35 ejecuciones con distintas semilla de cada instancia..
		{
		        my @configuration2 = split ' ', $line;#~ s/ /_/g; 
                        my $inst = $configuration2[0];	
                        my $nvar = $configuration2[1];	
                        my $nobj = $configuration2[2];	
			print $fout "~$PathAlgorithm/Ejecutable --n 100 --nfes 25000000 --nvar $nvar --Instance $inst --Path $PathAlgorithm --Dist_factor $Di --nobj $nobj --Seed $Seed --param_l 20 --param_k 4 \n";
		}
	}
}
