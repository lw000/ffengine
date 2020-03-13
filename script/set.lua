
local Set = {}

function Set:create(o)
	local set = o or {}
	setmetatable(set, self)
	
	self.__index = self
	self.__tostring = function(t)
		return string.format("{width:%d height:%d}", t.width, t.height)
	end

	self.width = 0
	self.height = 0
	return set
end

return Set