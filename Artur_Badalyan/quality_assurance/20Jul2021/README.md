<h1 align="center"><img src="https://jmeter.apache.org/images/logo.svg" alt="Apache JMeter logo" /></h1>

##Jmeter installation
* [Jmeter](https://jmeter.apache.org/download_jmeter.cgi)
##Plugins installation
* [Python](https://www.python.org/downloads/)
* [Jmeter](https://jmeter.apache.org/download_jmeter.cgi)
* [JMeterPluginsCMD](https://jmeter-plugins.org/wiki/JMeterPluginsCMD/)
* [jpgc-dummy](https://jmeter-plugins.org/?search=jpgc-dummy)
* [PerfMon Server Agent](https://jmeter-plugins.org/wiki/PerfMon/)

## Add paths in ~/.bashrc
> *Instead userName, write your username*
> 
> export PATH="/home/userName/Downloads/ServerAgent-2.2.1:$PATH"
>
> export PATH="/home/userName/Downloads/apache-jmeter-5.4.1/bin:$PATH"


##After installation 
Place the result folder in the jmeter installation folder(apache-jmeter-5.4.1)


## How to run jmeter(with thread number)
For run jmeter by the number of threads and create a result.jtl file
Into apache-jmeter-5.4.1 folder/result

> jmeter -n -t 'Thread Group.jmx' -Jcount=20 -f -l result.jtl
> 
> *Write your number thread instead of 20*

## Generate image (.png)
For generate .png image by result.jtl
Into apache-jmeter-5.4.1/result

> JMeterPluginsCMD.sh --generate-png ./image.png --input-jtl ./result.jtl --plugin-type ResponseTimesOverTime --width 800 --height 600

##How to run with python
> python script.py



