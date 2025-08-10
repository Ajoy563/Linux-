read -p "Enter lower limit:" le
read -p "Enter upper limit:" ri

echo "Prime numbers between $le and $ri are:"

for ((num=le; num<=ri; num++))
do
    if(($num < 2))
    then
        continue
    fi
    prime=1
    for ((i=2; i*i<=num; i++))
    do
        if(($(($num % i)) == 0))
        then
            prime=0
            break
        fi
    done
    if(($prime == 1))
    then
        printf "%d " "$num"
    fi
done
echo
