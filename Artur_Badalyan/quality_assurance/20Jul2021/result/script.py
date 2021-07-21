import os

command = "jmeter -n -t 'Thread Group.jmx' -Jcount=20 -f -l ./result.jtl"
result = "./result.jtl"
image = "./image.png"
generateImage = "JMeterPluginsCMD.sh --generate-png ./image.png --input-jtl ./result.jtl --plugin-type ResponseTimesOverTime --width 800 --height 600"

if os.path.exists(result):
    os.remove(result)

if os.path.exists(image):
    os.remove(image)

os.system(command)
os.system(generateImage)