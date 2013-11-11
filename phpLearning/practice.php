<!--?php
$large_number = 1111111111111111111111111111111;
var_dump($large_number);
printf( "\n%s\n",gettype($large_number));

$small_number = 11111111;
var_dump($small_number);
printf( "\n%s\n", gettype($small_number));

?-->

<!--!?php 
$juices = array("apple", "pear", "grape" => "purple");

echo "He drank some juice mode of $juices[grape].".PHP_EOL;

error_reporting(E_ALL);

$arr = ["a",3=>"b","ab" =>"c", "d"];

var_dump($arr);

?-->

<?php 
$handle = opendir('.');
while(false != ($file = readdir($handle))) {
    $files[] = $file;
}
closedir($handle);
foreach ($files as $filename) {
    echo "$filename".PHP_EOL;
}
?>

<?php
$firstquarter  = array(1 => 'January', 'February', 'March');
print_r($firstquarter);
?>