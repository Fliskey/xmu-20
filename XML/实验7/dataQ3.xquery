xquery version "1.0";
declare function local:getFlight()
  as element()*
{
    for $a  in doc("Data.xml")/doc/Reservation[./date = "2005-12-24"]
    for $b  in doc("Data.xml")/doc/Flight
    where $b/@flightId = $a/flightRef
    return	$b  
};
declare function local:getNum()
  as element()*
{
    for $i in doc("Data.xml")/doc/Airport
    return	
			<NUM>
			{$i}
			<passNum>{count(local:getFlight()[./source=$i/@airId]) + count(local:getFlight()[./destination=$i/@airId])}</passNum>
            </NUM>
};
 
<all>
{
(:仔细观察了Data后，这里只有4个乘客啊，难道就使用这4个乘客进行计数，其他所有的飞机上都没有人?:)
for $x  in local:getNum()[./passNum > 0]
order by $x/passNum
return 	$x 		
}
</all>