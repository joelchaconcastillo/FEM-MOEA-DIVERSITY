#Con este script se genera la lista de ejecuciones....
#!/usr/bin/perl
use strict;
use warnings;
use Getopt::Long;
my $file = "ExecutionScalability";
my $fout;
open($fout, '>' ,$file);
my $PathAlgorithm =  `cd ..; pwd`;#"/home/joel.chacon/Current/MyResearchTopics/MOEA-D-Diversity/MOEAD-DE/vsd-moead-opt";
chomp $PathAlgorithm;
#my $Path = "/home/joel.chacon/Chacon/Tesis/MOEA-D_Diversity/Code_CEC09/moead_based_diversity_SBX/";
my $Instance=0;
my $Sed=0;

####Realizar la búsqueda del parámetro D inicial que proporcione mejores resultados
my @Conf =(
"UF1 2",
"UF4 2",
"UF5 2",
"UF10 3",
"UF9 3",
"UF8 3",
"DTLZ4 2",
"DTLZ4 3",
);




###foreach(@DI)
##{
##	foreach(@Conf)
##	{
##		for($Sed = 1; $Sed <=35; $Sed++) ##Realizar 35 ejecuciones con distintas semilla de cada instancia..
##		{
##			print $fout "~$PathAlgorithm/Ejecutable $_ $Sed \n";
##		}
##	}
##	
##}

my @Variables= ("50","100","250", "500", "1000");

foreach my $v (@Variables)
{
        foreach my $configuration (@Conf)
        {
                for(my $Sed = 1; $Sed <=35; $Sed++) ##Realizar 35 ejecuciones con distintas semilla de cada instancia..
                {

#			 my @configuration2 = split ' ', $line;#~ s/ /_/g; 
#                        my $inst = $configuration2[0];
#                        my $nvar = $configuration2[1];
#                        my $nobj = $configuration2[2];
#                        print $fout "~$PathAlgorithm/Ejecutable --n 100 --nfes ".($nfes*25000)." --nvar $nvar --Instance $inst --Path $PathAlgorithm --Dist_factor 0.4 --nobj $nobj --Seed $Seed --param_l 20 --param_k 4 \n";

                      my @configuration2 = split ' ', $configuration;#~ s/ /_/g; 

		     print $fout "~$PathAlgorithm/Ejecutable --n 100 --nfes 25000000 --Instance $configuration2[0] --nvar $v --nobj $configuration2[1] --Seed $Sed --Path $PathAlgorithm --Dist_factor 0.4 \n";
                }
        }

}

