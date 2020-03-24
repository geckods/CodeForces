require 'set'
nm = gets.chomp.split(" ").map(&:to_i)
powers = gets.chomp.split(" ").map(&:to_i)
pairs = []
n = nm[0]
m = nm[1]

m.times do
  pairs.push gets.chomp.split(" ").map(&:to_i)
end

nopairs = []


t = gets.to_i
forcedmove = false
selected = Set.new
justplayedpair = false
toplayforced = -1

(2*n).times do
#  puts "#{t} #{forcedmove} #{toplayforced} #{justplayedpair}"
  if t==2
    opponentmove = gets.to_i
    if opponentmove==-1
#      powers[nil] =0 
      exit
    end
    selected.add(opponentmove)
    powers[opponentmove-1] = 0
    forcedmove = false
    if not justplayedpair
      toplayforced = -1

      pairs.each do |pair|
        if pair.include?(opponentmove)
          forcedmove = true
          toplayforced = (pair - [opponentmove])[0]
          break
        end
      end
    end
    t=1

  else
    #your move
    if forcedmove
      toplay = toplayforced
      justplayedpair = false
    else
      #your move and it's free
      played = false
      pairs.each do |pair|
        if not selected.include?(pair[0])
          #play this pair
          toplay = pair.max
          score1 = powers[pair[0]-1]
          score2 = powers[pair[1]-1]

          if score1>score2
            toplay = pair[0]
          else
            toplay = pair[1]
          end

          played = true
          justplayedpair = true
        end
      end

      if not played
        toplay = powers.index(powers.max)+1
        justplayedpair = false
        #put the largest unselected no-pair dude
      end
    end

#    puts forcedmove
#    puts played
    puts toplay
    STDOUT.flush
    powers[toplay-1] = 0
    selected.add(toplay)
    t = 2
  end
end

