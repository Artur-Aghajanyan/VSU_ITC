import os

cmd = "jmeter -n -t 'View Results Tree.jmx' -Jcount=20 -f -l ./result.jtl"
res = "./result.jtl"
img = "./image.png"
generateImage = "JMeterPluginsCMD.sh --generate-png ./image.png --input-jtl ./result.jtl --plugin-type ResponseTimesOverTime --width 700 --height 700"

if os.path.exists(res):
    os.remove(res)

if os.path.exists(img):
    os.remove(img)

os.system(cmd)
os.system(generateImage)
