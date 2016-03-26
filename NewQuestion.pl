use Getopt::Long;
use warnings;
use File::Copy::Recursive qw(dircopy);
use File::Copy qw(move);
use File::Slurp qw(read_file write_file);

my $id;
my $results = GetOptions("id=i" => \$id);
my $formattedID = sprintf('Euler%03d', $id);
print "$id\n";
print "$formattedID \n";

dircopy('.\\eulertmp', ".\\$formattedID") or die("$!\n");

my @files = glob ("$formattedID\\eulertmp.*");
{
	foreach $file (@files)	{
		my $data = read_file $file, {binmode => ':utf8'};
		$data =~ s/Eulertmp/$formattedID/g;
		$data =~ s/ProblemNum/Problem $id/g;
		write_file $file, {binmode => ':utf8'}, $data;
		my ($ext) = $file =~ /(\.[^.]+)$/;
		my ($newFile) = "$formattedID\\$formattedID" . $ext;
		print $newFile . "\n";
		move $file, $newFile;
	}
}