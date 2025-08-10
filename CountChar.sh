echo "Enter a line of text:"
read line

words=$(echo "$line" | wc -w)

chars=$(echo -n "$line" | wc -c)

spaces=$(echo "$line" | grep -o " " | wc -l)
specials=$(echo "$line" | grep -o "[^a-zA-Z0-9 ]" | wc -l)

echo "Number of words: $words"
echo "Number of characters (including spaces): $chars"
echo "Number of white spaces: $spaces"
echo "Number of special symbols: $specials"
