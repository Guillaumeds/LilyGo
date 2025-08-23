#!/usr/bin/env python3
"""
Extract text from SIM7000 AT Command Manual PDF
"""

import os
import sys

def extract_pdf_text():
    pdf_path = "examples/Arduino_TinyGSM/ATdebug/SIM7000 Series_AT Command Manual_V1.06.pdf"
    output_path = "SIM7000_AT_Commands.md"
    
    try:
        # Try using PyPDF2
        import PyPDF2
        
        with open(pdf_path, 'rb') as file:
            pdf_reader = PyPDF2.PdfReader(file)
            
            markdown_content = "# SIM7000 Series AT Command Manual V1.06\n\n"
            markdown_content += f"**Total Pages:** {len(pdf_reader.pages)}\n\n"
            
            # Extract text from ALL pages (complete manual)
            max_pages = len(pdf_reader.pages)
            
            for page_num in range(max_pages):
                print(f"Processing page {page_num + 1}/{max_pages}")
                
                try:
                    page = pdf_reader.pages[page_num]
                    text = page.extract_text()
                    
                    if text.strip():
                        # Clean up the text
                        lines = text.split('\n')
                        cleaned_lines = []
                        
                        for line in lines:
                            line = line.strip()
                            if line and len(line) > 2:  # Skip very short lines
                                cleaned_lines.append(line)
                        
                        if cleaned_lines:
                            markdown_content += f"## Page {page_num + 1}\n\n"
                            markdown_content += '\n'.join(cleaned_lines) + "\n\n"
                            markdown_content += "---\n\n"
                
                except Exception as e:
                    print(f"Error on page {page_num + 1}: {e}")
                    continue
            
            # Write to file
            with open(output_path, 'w', encoding='utf-8') as md_file:
                md_file.write(markdown_content)
            
            print(f"Successfully extracted text to: {output_path}")
            return True
            
    except ImportError:
        print("PyPDF2 not installed. Installing...")
        os.system("pip install PyPDF2")
        return extract_pdf_text()  # Retry after installation
        
    except Exception as e:
        print(f"Error: {e}")
        return False

if __name__ == "__main__":
    extract_pdf_text()
