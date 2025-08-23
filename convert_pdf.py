#!/usr/bin/env python3
"""
Simple PDF to Markdown converter for SIM7000 AT Command Manual
"""

import sys
import os

try:
    import PyPDF2
except ImportError:
    print("PyPDF2 not found, trying to install...")
    os.system("pip install PyPDF2")
    import PyPDF2

def pdf_to_markdown(pdf_path, output_path):
    """Convert PDF to markdown format"""
    
    if not os.path.exists(pdf_path):
        print(f"Error: PDF file not found: {pdf_path}")
        return False
    
    try:
        with open(pdf_path, 'rb') as file:
            pdf_reader = PyPDF2.PdfReader(file)
            
            markdown_content = "# SIM7000 Series AT Command Manual\n\n"
            markdown_content += f"**Total Pages:** {len(pdf_reader.pages)}\n\n"
            
            for page_num, page in enumerate(pdf_reader.pages, 1):
                print(f"Processing page {page_num}/{len(pdf_reader.pages)}")
                
                try:
                    text = page.extract_text()
                    if text.strip():
                        markdown_content += f"## Page {page_num}\n\n"
                        markdown_content += text + "\n\n"
                        markdown_content += "---\n\n"
                except Exception as e:
                    print(f"Error extracting text from page {page_num}: {e}")
                    continue
            
            # Write to markdown file
            with open(output_path, 'w', encoding='utf-8') as md_file:
                md_file.write(markdown_content)
            
            print(f"Successfully converted PDF to markdown: {output_path}")
            return True
            
    except Exception as e:
        print(f"Error processing PDF: {e}")
        return False

if __name__ == "__main__":
    pdf_file = "examples/Arduino_TinyGSM/ATdebug/SIM7000 Series_AT Command Manual_V1.06.pdf"
    output_file = "SIM7000_AT_Command_Manual.md"
    
    print(f"Converting {pdf_file} to {output_file}")
    
    if pdf_to_markdown(pdf_file, output_file):
        print("Conversion completed successfully!")
        print(f"Output file: {output_file}")
    else:
        print("Conversion failed!")
