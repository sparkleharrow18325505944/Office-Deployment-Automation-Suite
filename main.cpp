# Office Deployment Automation: Core Script v2.6.0
param (
    [string]$ConfigPath = "config/deployment.xml"
)

Write-Host "[INFO] Starting Microsoft Office Deployment..." -ForegroundColor Cyan

# Check for Office Deployment Tool
if (-not (Test-Path ".\setup.exe")) {
    Write-Error "ODT setup.exe not found. Please download from Microsoft."
    exit 1
}

# Execute silent deployment
Start-Process -FilePath ".\setup.exe" -ArgumentList "/configure $ConfigPath" -Wait
Write-Host "[SUCCESS] Office Deployment Completed." -ForegroundColor Green