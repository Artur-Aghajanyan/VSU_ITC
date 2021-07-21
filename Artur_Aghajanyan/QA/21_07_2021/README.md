<h1 align="center"><img src="https://jmeter.apache.org/images/logo.svg" alt="Apache JMeter logo" /></h1>

An Open Source Java application designed to measure performance and load test applications.

# Installing
* Jmeter - https://jmeter.apache.org/download_jmeter.cgi
* JMeterPluginsCMD - https://jmeter-plugins.org/wiki/JMeterPluginsCMD/
* jpgc-dummy - https://jmeter-plugins.org/?search=jpgc-dummy
* PerfMon Server Agent - https://jmeter-plugins.org/wiki/PerfMon/
* Python - https://www.python.org/downloads/

# Add paths in .bashrc
* sudo vim ~/.bashrc
  * export PATH="/home/userName/Downloads/ServerAgent-2.2.1:$PATH"
  * export PATH="/home/userName/Downloads/apache-jmeter-5.4.1/bin:$PATH"
  
# How to run JMeter test .jmx from cmd
* startAgent.sh
* jmeter -n -t test.jmx -JcountOfThread=20 -f -l result.jtl
  * Where JcountOfThread is count of threads
  * test.jmx is name of .jmx script file

# How to make image from .jtl
* JMeterPluginsCMD.sh --generate-png imageName.png --input-jtl result.jtl --plugin-type ResponseTimesOverTime --width 800 --height 600

# How to run with python
* python script.py

# What plugins are needed for all this?
 1) JMeterPluginsCMD
 2) jpgc-dummy
 3) JMeter Plugins Manager
 4) PerfMon Server Agent

