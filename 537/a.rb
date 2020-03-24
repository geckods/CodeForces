if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

name1 = gets.chomp
name2 = gets.chomp

def isvowel(ch)
	return true if ["a","e","i","o","u"].include?(ch)
	false
end

if name1.length == name2.length
	(0..name1.length).each do |i|
		iv1 = isvowel(name1[i])
		iv2 = isvowel(name2[i])
		if (iv1 and not iv2) or (iv2 and not iv1)
			puts "No"
			exit
		end
	end
	puts "Yes"
else
	puts "No"
end