local set = require("set")
local student = require("student")

function server_init(id1, id2, message )
	print("server_init", id1, id2, message)

	return 0
end

function server_start( ... )
	print("server_start")
end

function server_stop( ... )
	print("server_stop")
end

function server_message( ... )
	print("server_message")
end

function main( ... )
	print("hello c++")

	print(cadd(10, 20))

	local s = set:create()
	print(s)

	local student = student.new()
	student:set("candy", 1024, 20, 1)

	print(student)

	local name, num, age, sex = student:get()
	print(name, num, age, sex)
	
end

main()
