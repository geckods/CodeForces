if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

str1 = gets.chomp.downcase
str2 = gets.chomp.downcase


if str1==str2
	puts 0
	exit
end

if [str1,str2] != [str1,str2].sort
	puts 1
else
	puts -1
end