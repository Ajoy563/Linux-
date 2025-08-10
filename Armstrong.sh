read -p "Enter a number: " num

original=$num
sum=0
while(($num > 0))
do
    digit=$(( num % 10 ))         
    sum=$(( sum + digit * digit * digit ))  
    num=$(( num / 10 ))           
done

if(($sum == $original))
then
    echo "$original is an Armstrong number."
else
    echo "$original is NOT an Armstrong number."
fi

