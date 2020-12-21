xquery version "1.0";

declare function local:getFlight1($air) as element()*
{
	for $f1 in //Flight
	where $f1/source = $air/@airId or $f1/destination = $air/@airId
	return $f1
};

declare function local:getAir() as element()*
{

	for $air in //Airport, $sum in count(local:getFlight1($air))
	order by $sum descending
	return <result> {$air}<count>{$sum}</count></result>

};

let $q := local:getAir()[position()=1]
return  $q