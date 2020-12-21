xquery version "1.0";
<flights>
{
	for $a in //Airport[name eq 'North Pole'], $f in //Flight
	where $f/source eq $a/@airId
	return $f 
}
</flights> 