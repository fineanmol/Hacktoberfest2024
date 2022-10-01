// Simple systeminformation program, like a basic version of neofetch

package main

import (
	"fmt"
	"log"
	"os"
	"os/user"
	"runtime"
	"time"

	"github.com/gookit/color"
	"github.com/shirou/gopsutil/v3/cpu"
	"github.com/shirou/gopsutil/v3/host"
	"github.com/shirou/gopsutil/v3/mem"
)

func main() {

	// Get Time
	dt := time.Now()
	color.Magenta.Println(dt.Format(time.ANSIC))

	// Get Hostname
	hostname, err := os.Hostname()
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Get User
	user, err := user.Current()
	if err != nil {
		log.Fatalf(err.Error())
		os.Exit(1)
	}

	username := user.Username

	color.Yellow.Printf("%s@%s\n", username, hostname)

	// Get OS/Platform
	osp, _ := host.Info()

	color.Red.Printf("Platform: %s %s \n", osp.Platform, osp.PlatformVersion)

	// Get Kernel
	kernel, _ := host.Info()

	color.Green.Printf("Kernel-version: %s \n", kernel.KernelVersion)

	// Get CPUs
	CPUinfo, _ := cpu.Info()

	color.Blue.Print("CPU Model: ", CPUinfo[0].ModelName, "\n")
	color.Cyan.Printf("CPU Cores: %d \n", runtime.NumCPU())

	// Get RAM
	v, _ := mem.VirtualMemory()

	color.FgMagenta.Printf("RAM: Total:%v Gb, Free:%v Gb\n", v.Total/1073741824, v.Free/1073741824)

	// Get Uptime
	uptime, _ := host.Uptime()

	days := uptime / (60 * 60 * 24)
	hours := (uptime - (days * 60 * 60 * 24)) / (60 * 60)
	minutes := ((uptime - (days * 60 * 60 * 24)) - (hours * 60 * 60)) / 60
	color.White.Printf("Uptime: %d days, %d hours, %d minutes \n", days, hours, minutes)

}
