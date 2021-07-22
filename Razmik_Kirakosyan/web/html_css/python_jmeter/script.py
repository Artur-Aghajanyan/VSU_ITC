import os

os.system("gnome-terminal -e '/home/razmik/ServerAgent-2.2.3/startAgent.sh'")

os.system ('/home/razmik/Downloads/apache-jmeter-5.4.1/bin/jmeter -Jthread=10 -n -t /home/razmik/MyTestPlan.jmx ')

os.system ('sh /home/razmik/Downloads/apache-jmeter-5.4.1/bin/JMeterPluginsCMD.sh --generate-png /home/razmik/image.png --input-jtl /home/razmik/file.jtl --plugin-type  PerfMon ')

