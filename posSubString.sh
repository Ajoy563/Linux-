echo "Enter the main string:"
read main_str

echo "Enter the substring:"
read sub_str

pos=$(awk -v s="$main_str" -v sub="$sub_str" 'BEGIN { print index(s, sub) }')

if [ "$pos" -ne 0 ]; then
    echo "The substring starts at position: $pos"
else
    echo "Substring not found."
fi
