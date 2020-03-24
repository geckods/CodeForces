x = gets.chomp.to_i

(1..x).each do |a|
  (1..x).each do |b|
    if a%b==0 and a*b>x and a/b<x
      puts "#{a} #{b}"
      exit
    end
  end
end

puts -1
