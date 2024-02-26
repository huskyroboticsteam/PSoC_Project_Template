# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\casey\Desktop\Robotics Stuff\PSoC_Project_Template\PSoC Project Template.cydsn\PSoC Project Template.cyprj
# Date: Mon, 26 Feb 2024 01:25:27 GMT
#set_units -time ns
create_clock -name {DBG_UART_SCBCLK(FFB)} -period 725 -waveform {0 362.5} [list [get_pins {ClockBlock/ff_div_5}]]
create_clock -name {CyRouted1} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFClk} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyExtClk} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/ext}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {DBG_UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 29 59} [list]


# Component constraints for C:\Users\casey\Desktop\Robotics Stuff\PSoC_Project_Template\PSoC Project Template.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\casey\Desktop\Robotics Stuff\PSoC_Project_Template\PSoC Project Template.cydsn\PSoC Project Template.cyprj
# Date: Mon, 26 Feb 2024 01:25:23 GMT
