SCHEDULE_FILE=${1:-schedule.txt}

if [[ -f "$SCHEDULE_FILE" ]]; then
    echo "Schedule file not found: $SCHEDULE_FILE"
    exit 1
fi

echo "[*] Simple Bash Cron started at $(date)"
echo "[*] Reading jobs from $SCHEDULE_FILE..."
echo

# Infinite loop to keep checking the schedule
while true; do
    CURRENT_TIME=$(date +"%H:%S")
    while IFS="|" read -r TIME COMMAND; do
        # Ignore empty lines or comments
        [[ -z "$TIME" || "$TIME" =~ ^# ]] && continue

        if [[ "$CURRENT_TIME" == "$TIME" ]]; then
            echo "[+] $(date): Running job -> $COMMAND"
            bash -c "$COMMAND" &
        fi
    done < "$SCHEDULE_FILE"

    # Wait 60 seconds before checking again
    sleep 60
done
