# NuttX-Chinese

## NuttX 实时操作系统

**NuttX** 是一种实时操作系统（RTOS），重点是标准兼容性和占用空间小。从 8 位到 32 位微控制器环境可扩展，NuttX 的主要管理标准是 Posix 和 ANSI 标准。Unix 和其他常见 RTOS（例如 VxWorks）的其他标准 API 被用于这些标准下不可用的功能，或者不适合深度嵌入式环境（例如 fork()）的功能。<br><br>
NuttX 于 2007 年由 [Gregory Nutt](http://nuttx.org/doku.php?id=wiki:developers:gregory_nutt) 在宽松的 BSD 许可下首次发布。

## 主要特征

* 符合标准。
* 内核任务管理。
* 模块化设计。
* 完全可抢占。
* 自然可扩展。
* 高度可配置。
* 可轻松扩展到新的处理器架构，SoC 架构或电路板架构。请参阅[移植指南](http://nuttx.org/doku.php?id=documentation:portingguide)。
* FIFO，round-robin 和 “sporadic” 调度。
* 实时，确定性，支持优先级继承。
* 滴答操作。
* POSIX/ANSI 类任务控件，命名消息队列，计数信号量，时钟/定时器，信号，线程，强健互斥锁，取消点，环境变量，文件系统。
* 类似 VxWorks 的任务管理和看门狗定时器。
* BSD 套接字接口。
* 管理先发制人的扩展。
* 具有地址环境（进程）的可选任务。
* 对称多处理（SMP）
* 可加载的内核模块；轻量级嵌入式共享库。
* 内存配置：（1）平面嵌入式构建，（2）使用 MPU 进行受保护的构建，以及（3）使用 MMU 构建内核。
* 内存分配器：（1）标准堆内存分配，（2）粒度分配器，（3）共享内存，以及（4）动态大小的进程堆。
* 线程本地存储（TLS）
* 可继承的 “控制终端” 和 I/O 重定向。伪终端。
* 按需分页。
* 系统日志记录
* 可以作为开放的平面嵌入式 RTOS 构建，也可以作为具有系统调用门接口的单独构建的安全内核构建。
* 内置的每个线程 CPU 负载测量。
* 自定义 NuttX C 库。
* 应用程序界面在 [NuttX 用户指南](http://nuttx.org/doku.php?id=documentation:userguide)中有详细记录。

## 支持的平台

* ARM
	* ARM7TDMI (TI TMS320 C5471, Calypso, MoxART, NXP LPC214x, LPC2378, STMicro STR71x)
	* ARM920T (Freescale i.MX1)
	* ARM926EJS (TI DM320, NXP LPC31xx)
	* ARM Cortex-A5 (Atmel SAMA5D2, SAMA5D3, SAMA5D4)
	* ARM Cortex-A8 (Allwinner A10)
	* ARM Cortex-A9 (NXP/Freescale i.MX6)
	* ARM Cortex-R4/R4F (TI TMS570, Samsung Artik)
	* ARM Cortex-M0 (nuvoTon NUC120, NXP/Freescale KL25Z, KL26Z, Atmel SAMD20/21, SAML21, ST Micro STM32 F0)
	* ARM Cortex-M3 (ST Micro STM32 F1/L4/F2, TI/Stellaris LM3S, NXP LPC17xx, Atmel SAM3U/3X, SiliconLabs EFM32)
	* ARM Cortex-M4 (with/without floating point unit: ST Micro STM32 F3/F4/L4, TI/Stellaris LM4F/TM4C, NXP LPC43xx/LPC54xx, Freescale Kinetis K20/K28/K40/60/64/66, Atmel SAM4C/4E/4S/4L, Infineon XMC4xxx, Nordic NRF52xxx)
	* ARM Cortex-M7 (Atmel SAMV71/SAME70, ST Micro STM32 F7, STM32 H7, NXP i.MX RT)
* Atmel AVR
	* Atmel 8-bit AVR (AT90USB, ATmega)
	* AVR32
* Freescale M68HCS12
* Intel
	* 80×86
* MIPS
	* MicroChip PIC32MX (MIPS32 24Kc)
	* MicroChip PIC32MZ (MIPS32 M14k)
* Misoc
	* LM32 (Qemu)
* OpenRISC
	* mor1kx
* Renesas/Hitachi
	* Renesas/Hitachi SuperH
	* Renesas M16C/26
* RISC-V
* Xtensa LX6
	* Expressif ESP32
* Zilog
	* Zilog Z16F ZNeo
	* Zilog eZ80 Acclaim!
	* Zilog Z8Encore!
	* Zilog Z80
* [完整清单](http://www.nuttx.org/Documentation/NuttX.html#platforms)

## 文件系统

* 微小的内存，根[伪文件系统](http://nuttx.org/doku.php?id=wiki:vfs:pseudo-file-system)。
* 虚拟文件系统（VFS）。
* 可安装的卷。绑定挂载点，文件系统和块设备驱动程序。
* 通用系统日志记录（SYSLOG）支持。
* FAT12/16/32 文件系统支持。
* NFS 客户端。客户端支持网络文件系统（NFS，版本 3，UDP）。
* NXFFS 。微小的 NuttX 磨损均衡 FLASH 文件系统。
* SMART 。Ken Pettit 的 FLASH 文件系统。
* ROMFS 文件系统支持。
* CROMFS 文件系统支持（压缩）。
* BINFS 伪文件系统支持。
* HOSTFS 文件系统支持（仅限模拟）。
* 联盟文件系统。支持组合和覆盖文件系统。
* UserFS 。提供用户应用程序文件系统。
* procfs/ 伪文件系统。
* 基于 SPI 的 MMC/SD/SDH 卡的通用驱动程序。
* [二进制加载](http://www.nuttx.org/Documentation/NuttXBinfmt.html)程序，支持以下格式：
	* 单独链接的 ELF 模块。
	* 单独链接 [NXFLAT](http://nuttx.org/doku.php?id=wiki:vfs:nxflat) 模块。NXFLAT 是一种二进制格式，可以从文件系统中进行 XIP。
* PATH 变量支持。
* 通过 TFTP 和 FTP（获取和放置），HTML（wget）和 Zmodem（sz 和 rz）进行文件传输。
* 英特尔 HEX 转换。

## 设备驱动

* VFS 支持字符和块驱动程序。
* 异步 I/O（AIO）。
* Network，USB (host)，USB (device)，serial，I2C，I2S，NAND，CAN，ADC，DAC，PWM，正交编码器，通用定时器和看门狗定时器驱动器架构。
* RAMDISK，pipes，FIFO，/dev/null，/dev/zero，/dev/random 和 loop 驱动程序。
* 基于 SPI 或 SDIO 的 MMC/SD/SDH 卡的通用驱动程序。
* [电源管理](http://www.nuttx.org/Documentation/NuttxPortingGuide.html#pwrmgmt)子系统。
* 内置 [FreeModBus](http://freemodbus.berlios.de/) 1.5.0 版提供的 ModBus 支持。
* 图形设备：帧缓冲驱动程序，图形和段 LCD 驱动程序。
* 音频子系统：CODEC，音频输入和输出驱动器。命令行和图形媒体播放器应用程序。
* 加密子系统。
* 输入设备：触摸屏，USB 键盘，USB 鼠标，模拟/离散开关，基于 GPIO 的按钮和键盘。
* 内存技术设备
* ADI 公司：支持模数转换（ADC），数模转换（DAC），多路复用器和放大器。
* 系统记录设备。

## C/C++ 库

* 标准 C 库完全集成到 OS 中。
* 包括通过标准数学库的浮点支持。
* 附加组件 uClibc++ 模块提供标准 C++ 库支持输入输出流，字符串，STL，RTTI，异常等（LGPL）。
* C++ 11 LLVM libc++ 的当代端口也可用。

## 联网

* 多网络接口支持；多个网络链路层支持。
* IPv4，IPv6，TCP/IP，UDP，ARP，ICMP，ICMPv6，IGMPv2（客户端）协议栈。
* 用户空间栈
* 流，数据报和原始数据包套接字。
* 地址族：IPv4/IPv6（AF_INET，AF_INET6），原始套接字（AF_PACKET），原始 IEEE 802.15.4（AF_IEEE802154），原始蓝牙（AF_BLUETOOTH）和本地 Unix 域套接字支持（AF_LOCAL）。
* 特殊的 INET 协议套接字：原始 ICMP 和 ICMPv6 协议 ping 套接字（IPPROTO_ICMP，IPPROTO_ICMP6）。
* 自定义用户套接字。
* IP 转发。
* DNS 名称解析 / NetDB 。
* IEEE 802.11 FullMac 。
* 无线电网络驱动程序：IEEE 802.15.4 MAC，通用分组无线电，蓝牙 LE 。
* 6LoWPAN 用于无线网络驱动程序（IEEE 802.15.4 MAC 和通用分组无线电）。
* SLIP，TUN/PPP，本地环回设备。
* 一个 cJSON 接口。
* 占用空间小。
* BSD 兼容套接字层。
* 网络实用程序（DHCP 服务器和客户端，SMTP 客户端，TELNET 服务器和客户端，FTP 服务器和客户端，TFTP 客户端，HTTP 服务器和客户端，PPPD，NTP 客户端）。可继承的 TELNET 服务器会话（作为 “控制终端”）。VNC 服务器。
* ICMPv6 自主自动配置
* NFS 客户端。客户端支持网络文件系统（NFS，版本 3，UDP）。
* 一个 NuttX 接口的 Jeff Poskanzer 的 [THTTPD](http://acme.com/software/thttpd/) HTTP 服务器与 [NXFLAT](http://nuttx.org/doku.php?id=documentation:nxflat) 集成，提供嵌入式 CGI 。
* PHY 链路状态管理。
* UDP 网络发现，XML RPC 服务器。
* XML RPC 服务器。
* 支持网络模块（如 ESP8266）。

## Flash 支持

* 适用于内存技术设备的 MTD 界面。
* NAND 支持。
* FTL 。简单的 Flash 转换层支持 FLASH 上的文件系统。
* NXFFS 。NuttX 耗损均衡 FLASH 文件系统。
* 支持基于 SPI 的 FLASH 设备。

## USB 支持

### USB 主机支持

* USB 主机架构，用于 USB 主控制器驱动程序和依赖于设备的 USB 类驱动程序。
* USB 主机控制器驱动程序可用于 Atmel SAMA5Dx，NXP LPC17xx，LPC31xx 和 STmicro STM32 。
* 依赖于设备的 USB 类驱动程序可用于 USB 大容量存储，CDC/ACM 串行通信，HID 键盘，HID 鼠标和 Xbox 游戏控制器。
* 无缝接头支持 USB 集线器。

### USB 设备支持

* 类似于小工具的架构，用于 USB 设备控制器驱动程序和依赖于设备的 USB 类驱动程序。
* 可用于 PIC32，Atmel AVR，SAM3，SAM4 和 SAMA5Dx，NXP LPC17xx，LPC214x，LPC313x 和 LPC43xx，Silicon Laboraties EFM32，STMicro STM32 F1，F2，F3 和 F4 以及 TI DM320 等的 USB 设备控制器驱动程序。
* 依赖于设备的 USB 类驱动程序可用于 USB 大容量存储，CDC/ACM 串行通信，RNDIS 网络和 PL2303 虚拟串行通信。
* 可动态配置的复合 USB 设备。
* 内置 [USB 跟踪](http://nuttx.org/Documentation/UsbTrace.html)功能，用于 USB 调试。

## 图形支持

* Framebuffer 驱动程序。
* 用于并行和串行 LCD 和 OLED 器件的图形 LCD 驱动器。
* 分段 LCD 驱动程序。
* 串行到帧缓冲转换支持。
* FTDI/Bridgetek [FT800](http://www.ftdichip.com/Products/ICs/FT800.html) 和 [FT801](http://www.ftdichip.com/Products/ICs/FT801.html) GUI 驱动程序。
* mmap-able framebuffer 字符驱动程序。
* [LittlevGL](https://littlevgl.com/) 支持 framebuffer 驱动程序。
* VNC 服务器。
* [NX 图形子系统](http://nuttx.org/doku.php?id=documentation:nxgraphics)：图形库，窗口系统和字体支持，可与帧缓冲或 LCD 驱动程序配合使用。
* [NuttX 小部件](http://nuttx.org/doku.php?id=documentation:nxwidgets)：用保守的 C++ 编写的图形用户界面，与 NX 图形集成。
* [NuttX 窗口管理器](http://nuttx.org/doku.php?id=wiki:graphics:nxwm)：基于 [NX 图形子系统](http://nuttx.org/doku.php?id=documentation:nxgraphics)和 [NuttX 窗口小部件](http://nuttx.org/doku.php?id=documentation:nxwidgets)的小型窗口管理器。

## 加载项

### NuttShell

适用于 NuttX 的小型，可扩展，类似 bash 的外壳，具有丰富的功能和小巧的占地面积。请参阅 [NuttShell](http://nuttx.org/doku.php?id=documentation:nuttshell) 用户指南。

### Pascal Runtime

Pascal 附加组件可从 [Bitbucket.org](https://bitbucket.org/nuttx/pascal/downloads/) 网站下载。

### apps/Package

应用程序/软件包不是严格的部分或 NuttX，但保留在 NuttX GIT 存储库中，并作为单独的版本化软件包发布 NuttX。这些应用程序/软件包包含一系列 NuttX 应用程序，包括 NuttShell（NSH），网络实用程序，测试和示例，解释程序和 NSH 扩展命令。