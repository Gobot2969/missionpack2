# Writes DESC_TEXT to DESC_FILE with no trailing newline, matching
# release.bat's `<nul set /p ="..." > description.txt`.
file(WRITE "${DESC_FILE}" "${DESC_TEXT}")
