describe three vulnerabilities, at least,
create attacks against 3 vulnerabilities


read bigendian might be something theres already a func that does it 
overload size, its unsigned and could be -2 and passs

line 60 void pointer

1777 printf(logging_fmt, info->width, info->height, time_str, info->create_time);
this is vulnerable to a string format attack

shellcode_target = 0x4027c1
info = 40e420

what to do
mention what tools used

Your threat modeling diagram should include at least one data-flow diagram showing the architecture and a text description of the parts of the architecture, the flows between them, and which threats are possible given the data flows. Your diagram should include more detail than having just one box representing the bcimgview program. Instead you should show some of the internal functional structure of the program: which parts of the functionality involve computation on different kinds of data? The purpose of this level of detail is to guide thinking your about threats

