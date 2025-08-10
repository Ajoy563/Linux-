echo "Enter three numbers separated by space:"
read a b c
echo "All possible combinations are:"

for i in $a $b $c
do
    for j in $a $b $c
    do
        for k in $a $b $c
        do
	    if((i != j && i!= k && j != k))
	    then
                echo "$i $j $k"
	    fi
        done
    done
done
