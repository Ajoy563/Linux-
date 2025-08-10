echo "Enter first number:"
read num1
echo "Enter second number:"
read num2

a=$num1
b=$num2

while [ $b -ne 0 ]
do
    temp=$b
    b=$(( a % b ))
    a=$temp
done

echo "The GCD of $num1 and $num2 is: $a"
