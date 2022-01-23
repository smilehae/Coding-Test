//장르별로 묶기
//총 플레이 시간, 플레이되는 노래들 ( 2개까지)
//선생님의 엄청난 풀이...

function solution(genres, plays) {
    const genreMap = new Map();
    
    genres
        .map((genre,index)=>[genre,plays[index]])
        .forEach(([genre,play],index)=>{
        const data = genreMap.get(genre) || {total:0, song:[]};
        genreMap.set(genre,{
            total:data.total + play,
            song:[...data.song, {play,index}]
                .sort((a,b)=>b.play-a.play)
                .slice(0,2)
        });
    });
    return ([...genreMap.entries()]
               .sort((a,b)=>b[1].total - a[1].total)
               .flatMap(item=>item[1].song)
                .map(item=>item.index)
               );
        
    
    
}