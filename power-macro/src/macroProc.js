const addonPath = './native/pm-win-api/pm-win-api.node';
// eslint-disable-next-line @typescript-eslint/no-var-requires
const winAPI = require(addonPath);

function readMacro(path){
    winAPI.winOpenFile(path);
    winAPI.winReadMacroFile();
    winAPI.winCloseFile();
}

function runMacro(msPerTick = 5){
    winAPI.winAutoPerform(msPerTick);
}

function handleFileSelect(event) {
    const file = event.target.files[0];
    return URL.createObjectURL(file);
}

readMacro('../commands.txt');
runMacro(5);