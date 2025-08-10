echo "Enter elements separated by space:"
read -a arr
echo "Original array: ${arr[@]}"

echo "Enter the position to delete (starting from 1):"
read pos
index=$((pos - 1))

for (( i=index; i< ${#arr[@]}-1; i++ ))
do
    arr[i]=${arr[i+1]}
done

unset arr[${#arr[@]}-1]
echo "Array after deletion: ${arr[@]}"
