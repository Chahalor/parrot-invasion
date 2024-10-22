#!/bin/bash

script_path="$(realpath ./parrot_invasion.sh)"
cron_job="* * * * *  bash $script_path"
# echo "cron job : $cron_job"
# echo "invadeur script_path : $(realpath ./parrot_invasion.sh)"
chmod -x ./parrot_invasion.sh

if crontab -l 2>/dev/null | grep -q "$cron_job"; then
	bash ./parrot_invasion.sh
	echo "already setup on the crontab"
else
	echo "setup crontab"
	crontab -l 2>/dev/null > stockcron
	echo "$cron_job" >> stockcron
	crontab stockcron
	rm stockcron
fi