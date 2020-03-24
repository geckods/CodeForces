t = gets.to_i

def get_num(s)
  return s.ord-97
end

def bpm(posshash, u, seen, matchR,k)
  (0..k-1).each do |v|
    if posshash[u].include?(v) and not (seen[v]==1)
      seen[v] = 1
      if (matchR[v] < 0 || bpm(posshash, matchR[v],seen, matchR,k)) 
        matchR[v] = u 
        return true
      end
    end
  end

  return false
end

def maxBPM(posshash,k) 
    matchR = [] 
    (0..k-1).each do |i|
      matchR[i] = -1
    end  
    result = 0

    (0..k-1).each do |u|
        
        seen = []
        (0..k-1).each do |i|
          seen[i] = 0
        end
        result = result + 1 if (bpm(posshash, u, seen, matchR,k)) 
    end
    return [result,matchR]
end

 
=begin
bool bpm(bool bpGraph[M][N], int u, 
         bool seen[], int matchR[]) 
{ 
    // Try every job one by one 
    for (int v = 0; v < N; v++) 
    { 
        // If applicant u is interested in  
        // job v and v is not visited 
        if (bpGraph[u][v] && !seen[v]) 
        { 
            // Mark v as visited 
            seen[v] = true;  
  
            // If job 'v' is not assigned to an  
            // applicant OR previously assigned  
            // applicant for job v (which is matchR[v])  
            // has an alternate job available.  
            // Since v is marked as visited in  
            // the above line, matchR[v] in the following  
            // recursive call will not get job 'v' again 
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], 
                                     seen, matchR)) 
            { 
                matchR[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
  
// Returns maximum number 
// of matching from M to N 
int maxBPM(bool bpGraph[M][N]) 
{ 
    // An array to keep track of the  
    // applicants assigned to jobs.  
    // The value of matchR[i] is the  
    // applicant number assigned to job i, 
    // the value -1 indicates nobody is 
    // assigned. 
    int matchR[N]; 
  
    // Initially all jobs are available 
    memset(matchR, -1, sizeof(matchR)); 
  
    // Count of jobs assigned to applicants 
    int result = 0;  
    for (int u = 0; u < M; u++) 
    { 
        // Mark all jobs as not seen  
        // for next applicant. 
        bool seen[N]; 
        memset(seen, 0, sizeof(seen)); 
  
        // Find if the applicant 'u' can get a job 
        if (bpm(bpGraph, u, seen, matchR)) 
            result++; 
    } 
    return result; 
}
=end


t.times do
  k = gets.to_i
  s = gets.chomp
  a = gets.chomp
  b = gets.chomp

  minhash = Hash.new(0)
  maxhash = Hash.new(25)

  toquit = false

  s.each_char.with_index do |ch,i|
    ch = get_num(ch)
    minhash[ch] = [minhash[ch],get_num(a[i])].max
    maxhash[ch] = [maxhash[ch],get_num(b[i])].min
  
    if minhash[ch]>maxhash[ch]
      puts "NO"
      toquit = true
      break
    end
  end

  break if toquit

  posshash = Hash.new([])

  (0..k-1).each do |i|
    (minhash[i]..maxhash[i]).each do |j|
      posshash[i] += [j]
    end
  end

  asd = maxBPM(posshash,k)
  abc = asd[0]

  if abc < k
    puts "NO"
    next
  end

  puts "YES"
#  p posshash
#  p asd[1]
  (0..k-1).each do |z|
    print (asd[1].index(z)+97).chr
  end
#  asd[1].each do |z|
#    print (z+97).chr
#  end
  puts
end

