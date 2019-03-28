#Con este script se genera la lista de ejecuciones....
#!/usr/bin/perl
use strict;
use warnings;
use Getopt::Long;
my $Cores;
my $ini;
my $fin;
GetOptions (
		"Cores=i" => \$Cores,
		"S=i" => \$ini,
		"E=i"=> \$fin
	 )
	or die ("Error in comand line arguments") ;
my $i;
for($i = $ini; $i <= $fin; $i++)
{
	print "c-1-$i $Cores\n";
}
