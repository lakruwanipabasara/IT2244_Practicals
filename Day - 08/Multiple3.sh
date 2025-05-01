03) Multiples of 3 between 1 and 50:

echo "Multiples of 3 between 1 and 50: "

num=50/3

for((i=1;i<=num;i++))
do
mul=$((3*$i))  // Increment i by 3
echo $mul      //Print the result
done

OUTPUTS:

[paba@MSI ~]$ touch multiple3.sh
[paba@MSI ~]$ vi multiple3.sh
[paba@MSI ~]$ chmod 777 multiple3.sh
[paba@MSI ~]$ ./multiple3.sh
Multiples of 3 between 1 and 50:
3
6
9
12
15
18
21
24
27
30
33
36
39
42
45
48
