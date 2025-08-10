while true
do
    :
done &
pid1=$!

while true
do
    :
done &
pid2=$!

echo "First process is running in background with PID: $pid1"
echo "Second process is running in background with PID: $pid2"

sleep 5

kill $pid1
kill $pid2

echo "Both processes have been stopped."
