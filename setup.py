#!/usr/bin/env python3
"""
🛰️ LilyGO T-SIM7000G Project Setup Script

This script helps set up the development environment and configure
the project for your specific WiFi network and ThingSpeak channel.

Usage:
    python setup.py --wifi-ssid "Your Network" --wifi-password "password"
    python setup.py --interactive
    python setup.py --help
"""

import argparse
import os
import sys
import re
from pathlib import Path

def update_wifi_config(ssid, password, hostname="lilygo-sim7000g", ota_password="lilygo123"):
    """Update WiFi configuration file with user credentials."""
    config_file = Path("include/wifi_config.h")
    
    if not config_file.exists():
        print(f"❌ Error: {config_file} not found!")
        return False
    
    # Read current config
    with open(config_file, 'r') as f:
        content = f.read()
    
    # Update WiFi credentials
    content = re.sub(
        r'#define WIFI_SSID\s+"[^"]*"',
        f'#define WIFI_SSID           "{ssid}"',
        content
    )
    content = re.sub(
        r'#define WIFI_PASSWORD\s+"[^"]*"',
        f'#define WIFI_PASSWORD       "{password}"',
        content
    )
    content = re.sub(
        r'#define OTA_HOSTNAME\s+"[^"]*"',
        f'#define OTA_HOSTNAME        "{hostname}"',
        content
    )
    content = re.sub(
        r'#define OTA_PASSWORD\s+"[^"]*"',
        f'#define OTA_PASSWORD        "{ota_password}"',
        content
    )
    
    # Write updated config
    with open(config_file, 'w') as f:
        f.write(content)
    
    print(f"✅ Updated WiFi configuration:")
    print(f"   📶 SSID: {ssid}")
    print(f"   🔑 Password: {'*' * len(password)}")
    print(f"   🏠 Hostname: {hostname}")
    print(f"   🔐 OTA Password: {ota_password}")
    
    return True

def update_thingspeak_config(channel_id, write_key, read_key):
    """Update ThingSpeak configuration."""
    config_file = Path("include/config.h")
    
    if not config_file.exists():
        print(f"❌ Error: {config_file} not found!")
        return False
    
    # Read current config
    with open(config_file, 'r') as f:
        content = f.read()
    
    # Update ThingSpeak settings
    content = re.sub(
        r'#define THINGSPEAK_CHANNEL_ID\s+\d+',
        f'#define THINGSPEAK_CHANNEL_ID       {channel_id}',
        content
    )
    content = re.sub(
        r'#define THINGSPEAK_WRITE_API_KEY\s+"[^"]*"',
        f'#define THINGSPEAK_WRITE_API_KEY    "{write_key}"',
        content
    )
    content = re.sub(
        r'#define THINGSPEAK_READ_API_KEY\s+"[^"]*"',
        f'#define THINGSPEAK_READ_API_KEY     "{read_key}"',
        content
    )
    
    # Write updated config
    with open(config_file, 'w') as f:
        f.write(content)
    
    print(f"✅ Updated ThingSpeak configuration:")
    print(f"   📊 Channel ID: {channel_id}")
    print(f"   🔑 Write Key: {write_key[:8]}...")
    print(f"   📖 Read Key: {read_key[:8]}...")
    
    return True

def check_platformio():
    """Check if PlatformIO is installed."""
    try:
        import subprocess
        result = subprocess.run(['pio', '--version'], capture_output=True, text=True)
        if result.returncode == 0:
            print(f"✅ PlatformIO found: {result.stdout.strip()}")
            return True
    except FileNotFoundError:
        pass
    
    print("❌ PlatformIO not found!")
    print("📥 Install PlatformIO:")
    print("   pip install platformio")
    print("   or visit: https://platformio.org/install")
    return False

def interactive_setup():
    """Interactive setup wizard."""
    print("🛰️ LilyGO T-SIM7000G Interactive Setup")
    print("=" * 50)
    
    # WiFi Configuration
    print("\n📶 WiFi Configuration:")
    ssid = input("Enter WiFi SSID: ").strip()
    password = input("Enter WiFi Password: ").strip()
    hostname = input("Enter device hostname [lilygo-sim7000g]: ").strip() or "lilygo-sim7000g"
    ota_password = input("Enter OTA password [lilygo123]: ").strip() or "lilygo123"
    
    if ssid and password:
        update_wifi_config(ssid, password, hostname, ota_password)
    else:
        print("⚠️ Skipping WiFi configuration (empty SSID or password)")
    
    # ThingSpeak Configuration
    print("\n📊 ThingSpeak Configuration:")
    print("Current settings: Channel 2976042")
    update_ts = input("Update ThingSpeak settings? [y/N]: ").strip().lower()
    
    if update_ts == 'y':
        channel_id = input("Enter ThingSpeak Channel ID [2976042]: ").strip() or "2976042"
        write_key = input("Enter Write API Key [RWE803O3NIOLIUQS]: ").strip() or "RWE803O3NIOLIUQS"
        read_key = input("Enter Read API Key [R7AY7KIC6W4M6Y3I]: ").strip() or "R7AY7KIC6W4M6Y3I"
        update_thingspeak_config(channel_id, write_key, read_key)
    
    # Build and Upload
    print("\n🔨 Build and Upload:")
    build_now = input("Build project now? [y/N]: ").strip().lower()
    
    if build_now == 'y':
        if check_platformio():
            print("🔨 Building project...")
            os.system("pio run -e T-SIM7000G")
            
            upload_now = input("Upload to device now? [y/N]: ").strip().lower()
            if upload_now == 'y':
                print("📤 Uploading to device...")
                os.system("pio run -e T-SIM7000G -t upload")
    
    print("\n🎉 Setup complete!")
    print("\n📋 Next steps:")
    print("1. Connect your LilyGO T-SIM7000G via USB")
    print("2. Insert SIM card and connect antennas")
    print("3. Upload: pio run -e T-SIM7000G -t upload")
    print("4. Monitor: pio device monitor")
    print("5. Note device IP for OTA uploads")
    print("6. Use OTA: pio run -e T-SIM7000G-OTA -t upload")

def main():
    parser = argparse.ArgumentParser(
        description="🛰️ LilyGO T-SIM7000G Project Setup",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python setup.py --interactive
  python setup.py --wifi-ssid "MyNetwork" --wifi-password "mypassword"
  python setup.py --check-deps
        """
    )
    
    parser.add_argument('--interactive', '-i', action='store_true',
                       help='Run interactive setup wizard')
    parser.add_argument('--wifi-ssid', help='WiFi network SSID')
    parser.add_argument('--wifi-password', help='WiFi network password')
    parser.add_argument('--wifi-hostname', default='lilygo-sim7000g',
                       help='Device hostname for mDNS')
    parser.add_argument('--ota-password', default='lilygo123',
                       help='OTA upload password')
    parser.add_argument('--thingspeak-channel', help='ThingSpeak channel ID')
    parser.add_argument('--thingspeak-write-key', help='ThingSpeak write API key')
    parser.add_argument('--thingspeak-read-key', help='ThingSpeak read API key')
    parser.add_argument('--check-deps', action='store_true',
                       help='Check dependencies only')
    
    args = parser.parse_args()
    
    if args.check_deps:
        check_platformio()
        return
    
    if args.interactive:
        interactive_setup()
        return
    
    # Non-interactive mode
    if args.wifi_ssid and args.wifi_password:
        update_wifi_config(args.wifi_ssid, args.wifi_password, 
                          args.wifi_hostname, args.ota_password)
    
    if args.thingspeak_channel and args.thingspeak_write_key:
        update_thingspeak_config(args.thingspeak_channel, 
                               args.thingspeak_write_key,
                               args.thingspeak_read_key or "")
    
    if not any([args.wifi_ssid, args.thingspeak_channel]):
        print("🛰️ LilyGO T-SIM7000G Setup")
        print("Use --interactive for guided setup or --help for options")

if __name__ == "__main__":
    main()
