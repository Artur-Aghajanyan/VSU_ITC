import os

comand = "jmeter -n -t ./test.jmx -JcountOfThread=20 -f -l ./result.jtl"
result = "./result.jtl"
agent = "startAgent.sh"
generator = "JMeterPluginsCMD.sh --generate-png ./image.png --input-jtl ./result.jtl --plugin-type ResponseTimesOverTime --width 800 --height 600"

if os.path.exists(result):
    os.remove(result)
    
if os.path.exists(image):
    os.remove(image)

os.system(agent)
os.system(comand)
os.system(generator)
