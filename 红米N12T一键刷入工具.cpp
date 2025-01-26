#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <sstream>
#include <windows.h>

using namespace std;
int s;
string deviceName = "���� Note 12 Turbo";
string deviceCode = "marble";
string projectName = "OrangeFox Recovery Project & KernelSU";
string recVer = "R11.1_11 Beta";
string recAuth = "Ctapchuk";
string bootVer = "OS1.0.14-CN";
string ksudVer = "v1.0.3(12018)";
string toolAuth = "AviderMin";
string buildDate = "2025.01.26";
string recImg = "OFRP-2025-01-19_RECOVERY-Test-marble.img";
string bootImg = "KernelSU_Patched_12018-marble-boot.img";
string apkFile = "KernelSU_v1.0.3_12018-release.apk";
string Group = "749222815";

void MENU();
void INF();
void IN_SYSTEM();
void FASTBOOT_MODE();
void INSTALL_KERNELSU();
void REBOOT_FASTBOOT_FLASH_REC();
void REBOOT_FASTBOOT_FLASH_BOOT();
void REC_FLASHING();
void REC_FLASH_OVER();
void BOOT_FLASHING();
void BOOT_FLASH_OVER();
void FLASH_FAILED();
bool CheckDeviceCode();
bool CheckADBDevice();

int main() {
    system("color 3f");
    system(("TITLE " + deviceName + "һ��ˢ�빤�� --By " + toolAuth).c_str());
    INF();
    cout << "���س�������..." << endl;
    cin.get();
    system("cls");
    MENU();
    system("pause");
    return 0;
}

void INF() {
    cout << endl;
    cout << "     " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "                ���������Ϣ" << endl;
    cout << "        ���߼�    ��" << projectName << endl;
    cout << "        Rec�汾   ��" << recVer << endl;
    cout << "        Rec����   ��" << recAuth << endl;
    cout << "        Boot�汾  ��" << bootVer << endl;
    cout << "      KernelSU�汾��" << ksudVer << endl;
    cout << "        �������  ��" << deviceName << endl;
    cout << "        ���ʹ���  ��" << deviceCode << endl;
    cout << "        ��������  ��" << toolAuth << endl;
    cout << "        ����ʱ��  ��" << buildDate << endl;
    cout << "       ˢ������Ⱥ ��" << Group << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
}

void MENU() {
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "	     ��ѡ���ܣ�" << endl;
    cout << "" << endl;
    cout << "   1. �ڿ���״̬��ˢ��Recovery�������ͼ�飬�Ƽ���" << endl;
    cout << "" << endl;
    cout << "   2. ��Fastbootģʽ��ˢ��Recovery" << endl;
    cout << "" << endl;
    cout << "   3. ��װKernelSUӦ�ò�ˢ��KernelSU" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    int choice;
    do {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "��ѡ���˿���״̬������ִ��������Bootloader����.." << endl;
                Sleep(2);
                IN_SYSTEM();
                return;
            case 2:
                cout << "��ѡ����fastbootģʽ������ִ��ˢ�����..." << endl;
                Sleep(2);
                system("cls");
                FASTBOOT_MODE();
                return;
            case 3:
                cout << "��ѡ���˰�װKernelSU������ִ�а�װ����..." << endl;
                Sleep(2);
                system("cls");
                INSTALL_KERNELSU();
                return;
            default:
                cout << "��Ч��ѡ��������ѡ��" << endl;
                Sleep(1);
                system("cls");
                MENU();
                return;
        }

        cout << "����������ز˵�" << endl;
        cin.get();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << endl;

    } while (choice != 0);
    cout << "��лʹ�ã��ټ���" << endl;
    cout << "******************************" << endl;
}

void REC_FLASH_OVER() {
    system("cls");
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "             ˢдRecovery���" << endl;
    cout << endl;
    cout << "            �ֻ�����������Recovery" << endl;
    cout << endl;
    cout << "           " << toolAuth << "��л��ʹ�ñ�����" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "           ����������رմ˴��ڣ�" << endl;
    cout << endl;
    system("fastboot reboot recovery");
    system("pause");
	cin.get(); 
    exit(0);
    return;
}

void FLASH_FAILED() {
    system("cls");
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "                   ˢ��ʧ�ܣ�" << endl;
    cout << endl;
    cout << "           1.�����ֻ��ͺ��Ƿ���ȷ" << endl;
    cout << "           2.��ȷ��fastboot�Ƿ�����" << endl;
    cout << "           3.��ѹ���������б�����" << endl;
    cout << "             �������ɹ�������ϵ����" << endl;
    cout << endl;
    cout << "           " << toolAuth << "��л��ʹ�ñ�����" << endl;
    cout << endl;
    cout << "            ����������˳�����" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    return;
}

void REC_FLASHING() {
    system("cls");
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "          ���ڽ���ˢ��Recovery����" << endl; 
    cout << "      �������ʱ��ͣ���ڴ˽��棬���飺��" << endl;
    cout << endl;
    cout << "      ��1.USB���Ƿ���ȷ���ӡ�" << endl;
    cout << "      ��2.���������Ƿ���ȷ��װ��ʶ��" << endl;
    cout << "      ��3.�ֻ��Ƿ����fastbootģʽ��" << endl;
    cout << endl;
    cout << "             ���������ù��ߣ�" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    int result = system(("fastboot flash recovery_ab " + recImg).c_str());
    if (result == 0) {
        REC_FLASH_OVER();
    } else {
        FLASH_FAILED();
    }
    return;
}

void REBOOT_FASTBOOT_FLASH_REC() {
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "             �ֻ�������..." << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "   ������ʱ��ͣ���ڴ˽��棬�������ù��ߣ�" << endl;
    int result = system("adb reboot bootloader");
    if (result == 0) {
        REC_FLASHING();
    }
    return;
}

void REBOOT_FASTBOOT_FLASH_BOOT() {
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "             �ֻ�������..." << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "   ������ʱ��ͣ���ڴ˽��棬�������ù��ߣ�" << endl;
    int result = system("adb reboot bootloader");
    if (result == 0) {
        BOOT_FLASHING();
    }
    return;
}

void IN_SYSTEM() {
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "         �������ֻ���ȷ���ӵ����ԣ�" << endl;
    cout << endl;
    cout << "           ��ȷ����" << endl;
    cout << "      ��1.�ֻ�bootloaderδ����" << endl;
    cout << "      ��2.�ֻ����ڿ���״̬��" << endl;
    cout << "      ��3.�ֻ�����USB���ԡ�" << endl;
    cout << "      ��4.�������Ѿ���ȷ��װ������" << endl;
    cout << "      ��5.�ֻ���ʾUSB������Ȩʱ��ѡʼ�յ����Ȩ��" << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "     " << "���ڼ���豸�Ƿ���������..." << endl;
    cout << endl;
    cout << "   ������ʱ��ͣ���ڴ˽��棬�����������" << endl;
    cout << "***********************************************" << endl;

    if (CheckDeviceCode()) {
        cout << "�豸���ɹ����ѷ��������ӵ��豸��" << std::endl;
        cout << "�豸���������������Bootloader..." << std::endl;
        Sleep(3);
        REBOOT_FASTBOOT_FLASH_REC();
    }
}

void FASTBOOT_MODE() {
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "          �������ֻ���ȷ���ӵ����ԣ�" << endl;
    cout << endl;
    cout << "          ��ȷ����" << endl;
    cout << "        ��1.�ֻ�bootloaderδ����" << endl;
    cout << "        ��2.�ֻ�����fastbootģʽ��" << endl;
    cout << "        ��3.�������Ѿ���ȷ��װ������" << endl;
    cout << endl;
    cout << "            �����������������" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    REC_FLASHING();
    return;
}

void INSTALL_KERNELSU() {
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "          �������ֻ���ȷ���ӵ����ԣ�" << endl;
    cout << endl;
    cout << "          ��ȷ����" << endl;
    cout << "        ��1.�ֻ�������USB���ԡ�" << endl;
    cout << "        ��2.�����Ѱ�װADB������" << endl;
    cout << "        ��3.�ֻ�������Ȩ�˵��Եĵ���Ȩ�ޡ�" << endl;
    cout << "          ��������Ȩ�����ֶ���Ȩ" << endl;
    cout << endl;
    cout << "            �����������������" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cin.get();

    if (CheckDeviceCode()) {
        std::string installCommand = "adb install " + apkFile;
        int installResult = system(installCommand.c_str());
        if (installResult != 0) {
            std::cerr << "APK��װʧ�ܣ������ļ�·����ADB���ӣ�" << std::endl;
        } else {
            std::cout << "APK��װ�ɹ�����������Fastbootģʽˢ��KernelSU" << std::endl;
        }
        Sleep(2);
        REBOOT_FASTBOOT_FLASH_BOOT();
        system("cls");
        return MENU();
    }
}


void BOOT_FLASHING() {
    system("cls");
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "          ���ڽ���ˢ��Boot����" << endl; 
    cout << "      �������ʱ��ͣ���ڴ˽��棬���飺��" << endl;
    cout << endl;
    cout << "      ��1.USB���Ƿ���ȷ���ӡ�" << endl;
    cout << "      ��2.���������Ƿ���ȷ��װ��ʶ��" << endl;
    cout << "      ��3.�ֻ��Ƿ����fastbootģʽ��" << endl;
    cout << endl;
    cout << "             ���������ù��ߣ�" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    int result = system(("fastboot flash boot_ab " + bootImg).c_str());
    if (result == 0) {
        BOOT_FLASH_OVER();
    } else {
        FLASH_FAILED();
    }
    return;
}

void BOOT_FLASH_OVER() {
    system("cls");
    cout << "   " << deviceName << " һ��ˢ�빤��" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "             ˢдBoot���" << endl;
    cout << endl;
    cout << "            �ֻ�����������ϵͳ" << endl;
    cout << endl;
    cout << "           " << toolAuth << "��л��ʹ�ñ�����" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "           ����������رմ˴��ڣ�" << endl;
    cout << endl; // �ȴ��û����������
    system("fastboot reboot");
	cin.get(); // �����豸
    exit(0);  // �˳����򣬹رմ���
    return;
}

bool CheckDeviceCode() {
    cout << "���ڼ���豸����..." << endl;
    if (!CheckADBDevice()) {
        cout << "���󣺻��ͼ���쳣����������Ҫ��" << endl;
        cout << "��ȷ�������豸Ϊ " << deviceName << " ���ͣ���������������ȷ���豸��" << endl;
        char choice;
        do {
            cout << "���� r ���¼�飬������ q �˳�: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (choice != 'r' && choice != 'R' && choice != 'q' && choice != 'Q');

        if (choice == 'r' || choice == 'R') {
            return false; // �������¼��
        } else if (choice == 'q' || choice == 'Q') {
            cout << "���������˳�..." << endl;
            exit(0); // �˳�����
        }
    } else {
        cout << "���ͼ��ɹ����豸ƥ�䣡" << endl;
        return true;
    }
    return false;
}

bool CheckADBDevice() {
    std::string adbOutput = "";
    FILE * pipe = popen("adb shell getprop ro.product.vendor.name", "r");
    if (!pipe) {
        std::cerr << "Failed to execute adb shell getprop ro.product.vendor.name" << std::endl;
        return false;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe)) {
        adbOutput += buffer;
    }

    pclose(pipe);


    size_t pos;
    while ((pos = adbOutput.find_first_of("\n\r ")) != std::string::npos) {
        adbOutput.erase(pos, 1);
    }

    if (adbOutput == deviceCode) {
        return true;
    }

    return false;
}
