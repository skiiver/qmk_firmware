#SRC += muse.c # removed for space savings; we don't need music

# Note only need to add if overruling defaults in /planck/rev6/rules.mk
BOOTMAGIC_ENABLE = no		# Virtual DIP switch configuration, large storage
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no       # Commands for debug and configuration
AUDIO_ENABLE = no           # Audio output
#UNICODE_ENABLE = yes		# basically emojis but also international symbols that you want cross-platform compatible
#UNICODEMAP_ENABLE = yes

# defaults
#BOOTMAGIC_ENABLE = full      # Virtual DIP switch configuration
#MOUSEKEY_ENABLE = yes      # Mouse keys
#EXTRAKEY_ENABLE = yes       # Audio control and System control
#CONSOLE_ENABLE = yes         # Console for debug
#COMMAND_ENABLE = yes       # Commands for debug and configuration
#NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
#BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
#MIDI_ENABLE = no            # MIDI controls
#AUDIO_ENABLE = yes           # Audio output
#UNICODE_ENABLE = no         # Unicode
#BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
#RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
#WS2812_DRIVER = pwm
#API_SYSEX_ENABLE = no
