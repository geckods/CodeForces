if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nmp = gets.chomp.split(" ").map(&:to_i)