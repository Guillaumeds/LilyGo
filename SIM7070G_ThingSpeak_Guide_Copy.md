# SIM7070G ThingSpeak Integration Guide

## Complete Working AT Command Sequence

### Phase 1: Network Setup and Registration

```bash
# 1. Basic Communication Test
AT                              # Test modem response
# Expected: OK

# 2. Check Signal Quality
AT+CSQ                          # Signal strength (>10 recommended)
# Expected: +CSQ: XX,99 (where XX > 10)

# 3. Force GPRS Mode (Critical for TCP/HTTP)
AT+CNMP=13                      # Force GSM/GPRS only mode
# Expected: OK

# 4. Check Network Registration
AT+CREG?                        # Check GSM registration
# Expected: +CREG: 0,1 (registered)

# 5. Set APN for my.t Network
AT+CGDCONT=1,"IP","internet"    # Set PDP context with APN
# Expected: OK

# 6. Activate Data Connection
AT+CNACT=1,1                    # Activate PDP context
# Expected: OK, +APP PDP: 1,ACTIVE

# 7. Verify IP Address Assignment
AT+CNACT?                       # Check IP address
# Expected: +CNACT: 1,1,"10.x.x.x" (real IP address)

# 8. Test DNS Resolution
AT+CDNSGIP="api.thingspeak.com" # Test internet connectivity
# Expected: +CDNSGIP: 1,"api.thingspeak.com","IP_ADDRESS"
```

### Phase 2: HTTP Connection and Data Transmission

```bash
# 1. Configure HTTP Client
AT+SHCONF="URL","http://api.thingspeak.com"  # Set ThingSpeak URL
# Expected: OK

AT+SHCONF="BODYLEN",1024        # Set body length limit
# Expected: OK

AT+SHCONF="HEADERLEN",350       # Set header length limit  
# Expected: OK

# 2. Establish HTTP Connection
AT+SHCONN                       # Connect to ThingSpeak
# Expected: OK

# 3. Send Data to ThingSpeak
AT+SHREQ="/update?api_key=RWE803O3NIOLIUQS&field1=25.5&field2=60.2",1
# Expected: OK, +SHREQ: "GET",200,X (where X = response byte count)

# 4. Read Response (Use byte count from SHREQ response)
AT+SHREAD=0,X                   # Read X bytes (from SHREQ response)
# Expected: +SHREAD: X, ENTRY_NUMBER

# 5. Close HTTP Connection
AT+SHDISC                       # Disconnect HTTP session
# Expected: OK
```

## Response Byte Count Logic

### Parse SHREQ Response:
```
+SHREQ: "GET",200,2    → Read 2 bytes
+SHREQ: "GET",200,3    → Read 3 bytes  
+SHREQ: "GET",200,4    → Read 4 bytes
```

### Robust Reading Strategy:
- **Extract byte count** from `+SHREQ` response (number after last comma)
- **Use that exact count** in `AT+SHREAD=0,COUNT`
- **Always check for 200 status** before reading
- **Handle errors** if status ≠ 200

## ThingSpeak Field Mapping

```
Field 1: Battery Percentage (%)
Field 2: GPS Latitude  
Field 3: GPS Longitude
Field 4: GPS Altitude (m)
Field 5: Number of Satellites
Field 6: Battery Voltage (V)
Field 7: Cellular Signal Strength
```

## Error Handling

### Common Issues:
- **+CME ERROR: operation not allowed** → Connection not active, retry SHCONN
- **+SHREQ: "GET",400,X** → Bad request, check API key and URL format
- **No response from SHREQ** → Network timeout, check signal and retry
- **SHREAD error** → Use exact byte count from SHREQ response

### Recovery Sequence:
```bash
AT+SHDISC                       # Force disconnect
AT+CNACT=0,1                    # Deactivate PDP context
AT+CNACT=1,1                    # Reactivate PDP context
# Retry HTTP sequence
```

## Complete Example Session

```bash
AT+CSQ                          # Check signal
AT+CNMP=13                      # Force GPRS
AT+CREG?                        # Check registration
AT+CGDCONT=1,"IP","internet"    # Set APN
AT+CNACT=1,1                    # Activate data
AT+SHCONF="URL","http://api.thingspeak.com"
AT+SHCONN                       # Connect HTTP
AT+SHREQ="/update?api_key=RWE803O3NIOLIUQS&field1=25.5",1
# Parse response: +SHREQ: "GET",200,2
AT+SHREAD=0,2                   # Read 2 bytes
# Response: +SHREAD: 2, 83
AT+SHDISC                       # Disconnect
```
