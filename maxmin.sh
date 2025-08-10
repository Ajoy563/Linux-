echo "Enter elements with space:"
read -a arr

n=${#arr[@]} 
max=${arr[0]}
min=${arr[0]}
for((i=1; i<n; i++))
do
	if((${arr[i]} > max))
	then
		max=${arr[i]}
	fi

	if((${arr[i]} < min))
	then
		min=${arr[i]}
	fi
done

echo "Maximun: $max"
echo "Minimum: $min"	
