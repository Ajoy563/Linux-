filename="Student.txt"

while true
do
    echo ""
    echo "===== Student Record Menu ====="
    echo "a. Display the contents of the whole file"
    echo "b. Display the information of a student by Roll Number"
    echo "c. Delete the entry of a student by Roll Number"
    echo "d. Add a new entry"
    echo "e. Update an entry by Roll Number"
    echo "f. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        a)
            echo "---- All Students ----"
            cat "$filename"
            ;;
        b)
            read -p "Enter Roll Number to search: " roll
            grep "^$roll " "$filename" || echo "No student found with Roll Number $roll"
            ;;
        c)
            read -p "Enter Roll Number to delete: " roll
            grep -v "^$roll " "$filename" > temp.txt && mv temp.txt "$filename"
            echo "Record deleted (if existed)."
            ;;
        d)
            read -p "Enter Roll Number: " roll
            read -p "Enter Name: " name
            read -p "Enter City: " city
            echo "$roll $name $city" >> "$filename"
            sort -n -o "$filename" "$filename"
            echo "Record added."
            ;;
        e)
            read -p "Enter Roll Number to update: " roll
            if grep -q "^$roll " "$filename"; then
                read -p "Enter New Name: " name
                read -p "Enter New City: " city
                grep -v "^$roll " "$filename" > temp.txt
                echo "$roll $name $city" >> temp.txt
                sort -n temp.txt > "$filename"
                echo "Record updated."
            else
                echo "No student found with Roll Number $roll"
            fi
            ;;
        f)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid choice! Please try again."
            ;;
    esac
done
