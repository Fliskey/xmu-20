<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>
	<xsl:template match="/">
		<bib>
			<results>
				<xsl:apply-templates select="//section[count(ancestor::section)=0]"/>
			</results>
		</bib>
		
	</xsl:template>
	
	<xsl:template match="//section" name="sec">
		<xsl:copy>
			<xsl:copy-of select="@*"/>
			<xsl:copy-of select="./title"/>		
			<xsl:apply-templates select="./section"/>
		</xsl:copy>
	</xsl:template>
</xsl:stylesheet>
