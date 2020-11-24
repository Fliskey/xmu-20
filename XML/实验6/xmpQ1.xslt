<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>
	<xsl:template match="/">
		<xsl:element name="results">
			<xsl:apply-templates select="//book[count(author)>0]"/>
		</xsl:element>
	</xsl:template>
	<xsl:template match="book">
		<xsl:for-each select="author">
			<xsl:element name="result">
				<xsl:copy-of select="../title"/>
				<xsl:copy-of select="."/>
			</xsl:element>			
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
