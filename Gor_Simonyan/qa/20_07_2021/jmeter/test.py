import os

jmeter_path = "/home/gor/apache-jmeter-5.4.1/bin/"
server_agent_path = "./ServerAgent-2.2.3/"

result = "./result.jtl"

if os.path.exists(result):
    os.remove(result)

os.system("gnome-terminal -e '{}startAgent.sh'".format(server_agent_path))
os.system(jmeter_path + "jmeter -n -t ./Debug.Sampler.jmx -Jvar1=10")
os.system("sh " + jmeter_path + "JMeterPluginsCMD.sh --generate-png ./image.png --input-jtl ./result.jtl --plugin-type PerfMon")
