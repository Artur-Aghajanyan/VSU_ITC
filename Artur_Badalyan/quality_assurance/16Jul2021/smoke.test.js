const {Builder, By, Key, until} = require('selenium-webdriver');
const {assert} = require('chai')
const youtubeURL = 'https://youtu.be/LBl5A4BPyvk';
const text = 'hello';

test('smoke',async () => {
    let driver = new Builder().forBrowser('chrome').build();

    await driver.get('https://ytmp3.cc/youtubemp3/');
    await driver.findElement(By.id('submit')).click();
    let res = await driver.findElement(By.id('error')).getCssValue('display');
    assert.equal(res, 'block')

    await driver.get('https://ytmp3.cc/youtubemp3/');
    await driver.findElement(By.id('input')).sendKeys(youtubeURL, Key.RETURN);
    await new Promise(r => setTimeout(r, 3000));
    res = await driver.findElement(By.id('buttons')).getCssValue('display');
    assert.equal(res, 'block');

    await driver.get('https://ytmp3.cc/youtubemp3/');
    await driver.findElement(By.id('theme')).click();
    await new Promise(r => setTimeout(r, 3000));
    res = await driver.findElement(By.css('body')).getCssValue('background-color');
    assert.equal(res, 'rgba(12, 22, 39, 1)')

    await driver.quit();
},25000);

test('smoke',async () => {
    let driver = new Builder().forBrowser('chrome').build();
    await driver.get('https://comparetext.com/');
    await driver.findElement(By.id('a')).clear();
    await driver.findElement(By.id('a')).sendKeys(text, Key.RETURN);
    await driver.findElement(By.id('b')).clear();
    await driver.findElement(By.id('b')).sendKeys(text, Key.RETURN);
    await driver.findElement(By.css('#settings > table > tbody > tr:nth-child(1) > td > div.type-selector > p > label:nth-child(3) > input[type=radio]')).click();
    res = await driver.findElement(By.id('result')).getText();
    assert.equal(text,res,text);

    await driver.get('https://translate.google.com/?hl=ru&sl=en&tl=ru&op=translate');
    await driver.findElement(By.css('#yDmH0d > c-wiz > div > div.WFnNle > c-wiz > div.OlSOob > c-wiz > div.ccvoYb > div.AxqVh > div.OPPzxe > c-wiz.rm1UF.UnxENd > span > span > div > textarea')).sendKeys('Hello',Key.RETURN);
    await new Promise(r => setTimeout(r, 2000));
    res = await driver.findElement(By.css('#yDmH0d > c-wiz > div > div.WFnNle > c-wiz > div.OlSOob > c-wiz > div.ccvoYb > div.AxqVh > div.OPPzxe > c-wiz.P6w8m.BDJ8fb > div.dePhmb > div > div.J0lOec > span.VIiyi > span > span')).getText();
    assert.equal(res,'Привет');
    await driver.quit();

},15000);


