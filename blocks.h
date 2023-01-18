//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "if [ -s /tmp/screencast.pid ]; then printf \"[Recording]   \"; fi",	0,		10},
        {"Battery: ", "acpi | awk -F\", \" '{print $2}'",  5,  0},
        {" | Vol: ", "pamixer --get-volume-human | awk -F\"%\" '{if($1==\"muted\") printf \"MUTE \"; else printf $1\" \" }'",  0,  5},
        {"| CPU: ","uptime | awk -F\": \" '{ print $2 }' | awk -F\",\" '{printf $1\" - \"}'", 1,  0},
        {"","sensors | grep Package | awk -F\"+\" '{print $2}' | awk -F\".\" '{printf $1\"°C\"}'",   1,  0},
	{" | ", "echo -n $(date '+%a %d %b - %R')",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "";
static unsigned int delimLen = 5;
