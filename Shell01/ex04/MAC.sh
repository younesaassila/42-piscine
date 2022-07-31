ifconfig | grep -o -E 'ether (([0-9a-f]{2}:){5}[0-9a-f]{2})' | cut -c 7-
