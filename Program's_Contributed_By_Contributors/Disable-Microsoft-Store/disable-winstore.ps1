# Windows is a trademark of Microsoft Corporation.
# This script is not affiliated with Microsoft Corporation. 
# This script is provided "as is" with no warranty of any kind, express or implied. Use at your own risk.
# This script is provided as a courtesy to the community.
# It is not supported by Microsoft. If you have questions, please post them on the TechNet forums.

# Disable Windows Store in Windows 10/11 (1903+)

# Disable Windows Store
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\WindowsStore" -Name "AutoDownload" -Value 2 -Type DWord -Force

# Disable Windows Store Background Tasks (Windows 10/11 1903+)
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\WindowsStore" -Name "DisableBackgroundTasks" -Value 1 -Type DWord -Force

# Disable Windows Store Auto Update (Windows 10/11 1903+) 
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\WindowsStore" -Name "DisableOSUpgrade" -Value 1 -Type DWord -Force

# ================================================================
# AUTHOR: KARTHIK LAL & :: EMAIL: karthik.lal558@gmail.com
# TOOLS ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND AND THE AUTHOR IS NOT RESPONSIBLE FOR ANY DAMAGE CAUSED BY THE USE OF THESE TOOLS
# USE AT YOUR OWN RISK
# LISENSE: GNU GENERAL PUBLIC LICENSE V3.0
# OPENSOURCE SOFTWARE LICENSE AGREEMENT FOR WINDOWS DISTRIBUTION SYSTEM (https://www.gnu.org/licenses/gpl-3.0.en.html)
# Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved.
# Copyright (c) 2022 KARTHIK LAL
# ================================================================